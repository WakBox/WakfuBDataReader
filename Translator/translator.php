<?php

echo "\n";
echo ">> Starting translator.php...\n\n";

$binaryReaders = array();

if ($handle = opendir('./java'))
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
   		$outputData = $outputFile->ParseFile();
   		$outputFile->GenerateOutputFile($outputData);
   	}
}
else
	echo '>> Error while opening directory !';

class OutputFile
{
	private $fileName = '';
	private $file = [];

	private $mainClassStruct = [];
	private $subClassesStruct = [];

	private $outputFile = '';

	private $className = '';

	private $classes = [];

	private $functions = [];
	private $columns = [];

	private $translate = [
		'wtf??'						=> 'wtf??',
		'get'						=> 'ReadByte|qint8',
		'readBoolean'				=> 'ReadBool|bool',
		'getShort'					=> 'ReadShort|qint16',
		'getFloat'					=> 'ReadFloat|float',
		'getInt' 					=> 'ReadInt|qint32',
		'getLong'					=> 'ReadLong|qint64',
		'readUTF8'					=> 'ReadString|QString',
		'readByteArray'				=> 'ReadByteArray|QList<qint8>',
		'readShortArray'			=> 'ReadShortArray|QList<qint16>',
		'readIntArray'				=> 'ReadIntArray|QList<qint32>',
		'readFloatArray'			=> 'ReadFloatArray|QList<float>',
		'readLongArray'				=> 'ReadLongArray|QList<qint64>',
		'readStringArray' 			=> 'ReadStringArray|QList<QString>',
		'Timestamp'					=> 'ReadLong|qint64'
	];

	public function __construct($fileName)
	{
		$this->fileName = $fileName;
		$this->file = file('java/' . $fileName);
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
   		$file = explode('BinaryData', $this->fileName);
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
		$this->subClassesStruct = $this->ParseSubClassesStruct($classes['sub_classes']);

		//var_dump($this->subClassesStruct); die;

		// Step 3: Get main class struct
		$this->mainClassStruct = $this->ParseMainClassStruct($classes['main_class']);

		// Step 4: Generate output file
		$struct = '';

		foreach ($this->subClassesStruct as $name => $subClass)
		{
			$struct .= 'struct ' . $name . "\n" . '{' . "\n";
			foreach ($subClass as $entry)
			{
				if ($entry['type'] == 'sizeOfStruct')
					continue;

				if ($entry['type'] == 'struct')
				{
					$struct .= '    QList<' . $entry['function'] . '> ' . $entry['name'] . ";\n";
				}
				else
					$struct .= '    ' . $entry['type'] . ' ' . $entry['name'] . ";\n";
			}
			$struct .= '};' . "\n\n";
		}

		$struct .= 'struct ' . $classes['main_class']['name'] . "\n" . '{' . "\n";

		foreach ($this->mainClassStruct as $entry)
		{
			if ($entry['type'] == 'sizeOfStruct')
				continue;

			if ($entry['type'] == 'struct')
			{
				$struct .= '    QList<' . $entry['function'] . '> ' . $entry['name'] . ";\n";
			}
			else
				$struct .= '    ' . $entry['type'] . ' ' . $entry['name'] . ";\n";
		}

		$struct .= '};' . "\n";

		$reader = $classes['main_class']['name'] . ' entry;' . "\n\n";
		$totalEntries = count($this->mainClassStruct);

		for ($i = 0; $i < $totalEntries; ++$i)
		{
			$entry = $this->mainClassStruct[$i];

			if ($entry['type'] == 'struct')
				continue;

			if ($entry['type'] == 'sizeOfStruct')
			{
				$subClass = $this->ReadSubClass($entry, $this->mainClassStruct[++$i], $i, 'entry');
				$reader .= "\n" . $subClass['reader'] . "\n";
			}
			else
				$reader .= '            entry.' . $entry['name'] . ' = r->' . $entry['function'] . "\n";			
		}

		return [
			'struct' => $struct,
			'reader' => $reader
		];

		//echo '>> Error while opening file : ' . $file . "\n";
	}

	public function ReadSubClass($entry, $struct, $pos, $parentStruct, $depth = 0)
	{
		$tab = '            ';
		$tab .= str_repeat('    ', $depth);

		$letters = ['i', 'j', 'k', 'l', 'm', 'n'];

		$reader = $tab . 'qint32 ' . $entry['name'] . ' = r->' . $entry['function'] . "\n\n";
		$reader .= $tab . 'for (qint32 ' . $letters[$depth] . ' = 0; ' . $letters[$depth] . ' < ' . $entry['name'] . '; ++' . $letters[$depth] . ')' . "\n";
		$reader .= $tab . '{' . "\n";

		$reader .= $tab . '    ' . $struct['function'] . ' ' . lcfirst($struct['function']) . ';' . "\n\n";

		$end = count($this->subClassesStruct[$struct['function']]);

		foreach ($this->subClassesStruct[$struct['function']] as $k => $structEntry)
		{
			if ($structEntry['type'] == 'struct')
				continue;

			if ($structEntry['type'] == 'sizeOfStruct')
			{
				$subClass = $this->ReadSubClass($structEntry, $this->subClassesStruct[$struct['function']][++$k], $pos, lcfirst($struct['function']), ++$depth);
				
				$reader .= $subClass['reader'];
				$pos = $subClass['pos'];
			}
			else
				$reader .= $tab . '    ' . lcfirst($struct['function']) . '.' . $structEntry['name'] . ' = r->' . $structEntry['function'] . "\n";
		}

		$reader .= "\n" . $tab . '    ' . lcfirst($parentStruct) . '.' . $struct['name'] . '.push_back(' . lcfirst($struct['function']) . ');' . "\n";

		$reader .= $tab . '}' . "\n";

		return ['pos' => $pos, 'reader' => $reader];
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
			for ($i = $subClass['pos']; $i < $this->totalLines; ++$i)
			{
				$line = $lines[$i];

				if (strpos($line, 'read(final') !== false)
				{
					while (!empty($line))
					{
						$line = trim($lines[$i++]);
						$translated = $this->TranslateFunction($line, true);

						if (!empty($translated))
							$struct[$subClass['name']][] = $translated;
					}

					break;
				}
			}
		}

		return $struct;
	}

	public function ParseMainClassStruct($mainClass)
	{
		$struct = [];

		if (empty($mainClass))
			return $struct;

		$lines = $this->file;

		for ($i = $mainClass['pos']; $i < $this->totalLines; ++$i)
		{
			$line = $lines[$i];

			if (strpos($line, 'read(final') !== false)
			{
				while (!empty($line))
				{
					$line = trim($lines[$i++]);
					$translated = $this->TranslateFunction($line);

					if (!empty($translated))
						$struct[] = $translated;
				}

				break;
			}
		}

		return $struct;
	}

	public function TranslateFunction($line, $isSubStruct = false)
	{
		if (strpos($line, 'new') !== false and (strpos($line, 'read') === false) and (strpos($line, 'Timestamp') === false))
		{
			$func = explode(' = ', $line);
			$name = trim(str_replace('this.', '', $func[0]));

			$struct = explode('[', str_replace('new', '', $func[1]));
			$struct = trim($struct[0]);

			return ['name' => $name, 'type' => 'struct','function' => $struct];
		}
		else
		{
			$keys = array_keys($this->translate);

			if ($newFunc = $this->Contains($line, $keys))
			{
				$translated = explode('|', $this->translate[$keys[$newFunc]]);
				$function = $translated[0];
				$name = explode(' = ', $line)[0];

				if (strpos($name, 'final') !== false)
				{
					$name = explode(' ', $name);
					$name = trim($name[count($name) - 1]);

					$function .= '();';
					$type = 'sizeOfStruct';
				}
				else
				{
					$name = trim(str_replace('this.', '', $name));
					
					if (!$isSubStruct)
						$function .= '("' . $name . '");';
					else
						$function .= '();';

					$type = $translated[1];
				}

				return ['type' => $type, 'name' => $name, 'function' => $function];
			}
		}

		return null;
	}

	public function GenerateOutputFile($outputData)
	{
		echo ">> Generating output file \"$this->outputFile\"...\n";
		$template = file_get_contents('binaryStorageTemplate.txt');

		$template = str_replace('%includeGuards%', strtoupper($this->className), $template);
		$template = str_replace('%struct%', $outputData['struct'], $template);
		$template = str_replace('%className%', $this->className, $template);
		$template = str_replace('%reader%', $outputData['reader'], $template);

		//var_dump($template);

		file_put_contents('BinaryDataStructure.h', $outputData['struct'] . "\n", FILE_APPEND);

		file_put_contents('build/' . $this->outputFile, $template);
		echo ">> DONE\n\n";
	}
}