<?php

echo "\n";
echo ">> Starting translator.php...\n\n";

$binaryReaders = array();

if ($handle = opendir('.'))
{
    while (false !== ($entry = readdir($handle)))
    {
        if ($entry != '.' && $entry != '..'
         && strpos($entry, '.java') !== false)
            $binaryReaders[] = $entry;
    }

    closedir($handle);

    sort($binaryReaders);
    echo ">> Loaded " . sizeof($binaryReaders) . " binaryReaders.\n\n";

    foreach ($binaryReaders as $r)
   	{
   		echo ">> Openning " . $r . "\n";
   		$outputFile = new OutputFile($r);

   		$outputFile->GenerateOutputName();
   		$outputFile->ParseFile();
   		$outputFile->GenerateOutputFile();
   	}
}
else
	echo '>> Error while opening directory !';

class OutputFile
{
	private $fileName = '';
	private $file = [];

	private $outputFile = '';

	private $className = '';

	private $classes = [];

	private $functions = [];
	private $columns = [];

	private $translate = [
		'wtf??'						=> 'wtf??',
		'get'						=> 'ReadByte',
		'readBoolean'				=> 'ReadBool',
		'getShort'					=> 'ReadShort',
		'getFloat'					=> 'ReadFloat',
		'getInt' 					=> 'ReadInt',
		'getLong'					=> 'ReadLong',
		'readUTF8'					=> 'ReadString',
		'readByteArray'				=> 'ReadByteArray',
		'readIntArray'				=> 'ReadIntArray',
		'readShortArray'			=> 'ReadShortArray',
		'readFloatArray'			=> 'ReadFloatArray',
		'readStringArray' 			=> 'ReadStringArray',
		'readLongArray'				=> 'ReadLongArray'
	];

	public function __construct($fileName)
	{
		$this->fileName = $fileName;
		$this->file = file($fileName);
		$this->totalLines = count($this->file);
	}

	public function Contains($what, $in)
	{
		$pos = 0;
		foreach ($in as $i)
		{
			if (preg_match("/(".$i.")(\\(\\))/is", $what))
				return $pos;
			else
				++$pos;
		}

		return false;
	}

	public function GenerateOutputName()
	{
   		$file = explode('BinaryData', $this->file);
   		$this->outputFile = $file[0] . '.h';
   		$this->className = $file[0];
   		echo ">> Output filename : " . $this->outputFile . "\n";
	}

	public function ParseFile()
	{
		echo ">> Start parsing input file...\n";

		// Step 1: Get classes
		$classes = $this->ParseClasses();

		// Step 2: Get sub classes struct
		$subClassesStruct = $this->ParseSubClassesStruct($classes['sub_classes']);

		// Step 3: Get main class struct
		$this->ParseMainClassStruct();

		// TMP
		die;

		$handle = fopen($this->file, 'r');
		if ($handle) 
		{
			$lineNumber = 0;
		    while (($line = fgets($handle, 4096)) !== false)
		    {
				$this->ParseLine($line, ++$lineNumber);
		    }

		    var_dump($this->classes); die;

		    if (!feof($handle))
		        echo ">> Error: unexpected fgets() fail\n";

		    fclose($handle);
		}
		else
			echo '>> Error while opening file : ' . $file . "\n";
	}

	public function ParseClasses()
	{
		$classes = [];
		$lines = $this->file;

		foreach ($lines as $pos => $line)
		{
			if (empty($classes))
			{
				if (strpos($line, 'public class') !== false)
				{
					$className = explode(' implements ', $line)[0];
					$classes['main_class'] = [
						'name' => trim(str_replace('public class', '', $className)),
						'pos' => $pos + 1
					];
				}
			}
			else
			{
				if (strpos($line, 'public static class') !== false)
				{
					$className = explode(' static class ', $line)[1];
					$classes['sub_classes'][] = [
						'name' => trim($className),
						'pos' => $pos + 1
					];
				}					
			}
		}

		return $classes;
	}

	public function ParseSubClassesStruct($subClasses)
	{
		$struct = [];

		if (empty($subClasses))
			return $struct;

		$lines = $this->file;
		foreach ($subClasses as $subClass)
		{
			echo '<br><br>PARSING ' . $subClass['name'] . '<br><br>';
			for ($i = $subClass['pos']; $i < $this->totalLines; ++$i)
			{
				$line = $lines[$i];

				if (strpos($line, 'read(final') !== false)
				{
					while (!empty($line))
					{
						$line = trim($lines[$i++]);
						$translated = $this->TranslateFunction($line);

						if (!empty($translated))
							$struct[$subClass['name']][] = $translated;
					}

					var_dump($struct[$subClass['name']]);

					break;
				}
			}
		}
	}

	public function TranslateFunction($line)
	{
		if (strpos($line, 'new') !== false)
		{
			$name = explode(' = ', $line);
			$name = trim(str_replace('this.', '', $name[0]));

			$struct = str_replace('new', '', $name[1]);

			var_dump($name . ' : ' . $struct);
		}
		else
		{
			$keys = array_keys($this->translate);

			if ($newFunc = $this->Contains($line, $keys))
			{
				$function = $this->translate[$keys[$newFunc]];
				$name = explode(' = ', $line)[0];

				if (strpos($name, 'final') !== false)
				{
					$name = explode(' ', $name);
					$name = trim($name[count($name) - 1]);
					$function .= '();';
				}
				else
				{
					$name = trim(str_replace('this.', '', $name));
					$function .= '("' . $name . '");';
				}

				return ['name' => $name, 'function' => $function];
			}
		}

		return null;
	}

	public function GenerateOutputFile()
	{
		echo ">> Generating output file \"$this->outputFile\"...\n";
		$template = file_get_contents('binaryStorageTemplate.txt');
		$template = str_replace('%className%', $this->className, $template);

		$struct = '';
		foreach ($this->functions as $f)
			$struct .= '            d << r->' . $f . '();' . "\n";

		$template = str_replace('%struct%', $struct, $template);
		file_put_contents('build/' . $this->outputFile, $template);
		echo ">> DONE\n\n";
	}
}