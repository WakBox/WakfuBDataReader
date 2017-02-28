<?php

echo "\n";
echo ">> Starting translator.php...\n\n";

$binaryReaders = array();

if ($handle = opendir('.'))
{
    while (false !== ($entry = readdir($handle)))
    {
        if ($entry != '.' && $entry != '..'
         && $entry != 'translator.php')
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
	private $file = '';
	private $outputFile = '';

	private $className = '';

	private $functions = array();
	private $columns = array();

	private $translate = array(
		'wtf??'			=> 'wtf??',
		'get'			=> 'ReadByte|byte',
		'readBoolean'	=> 'ReadBool|bool',
		'getShort'		=> 'ReadShort|short',
		'getFloat'		=> 'ReadFloat|float', // à corriger
		'getInt' 		=> 'ReadInt|int',
		'getLong'		=> 'ReadLong|long',
		'readUTF8'		=> 'ReadString|string', //todo
		'clh'			=> 'ReadByteArray|byte array', // todo
		'cli'			=> 'ReadIntArray|int array', // todo
		'clj'			=> 'ReadShortArray|short array', // todo
		'clk'			=> 'ReadFloatArray|float array', // todo
		'cll'			=> 'ReadStringArray|string array', // todo
		'clm'			=> 'ReadLongArray|long array' // todo
	);

	public function __construct($file)
	{
		$this->file = $file;
	}

	public function Contains($what, $in)
	{
		$count = 0;
		foreach ($in as $i)
		{
			if (preg_match("/(".$i.")(\\(\\))/is", $what))
				return $count;
			else
				++$count;
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

		$handle = fopen($this->file, 'r');
		if ($handle) 
		{
		    while (($line = fgets($handle, 4096)) !== false)
				$this->ParseLine($line);

		    if (!feof($handle))
		        echo ">> Error: unexpected fgets() fail\n";

		    fclose($handle);
		}
		else
			echo '>> Error while opening file : ' . $file . "\n";
	}

	public function ParseLine($line)
	{
		$keys = array_keys($this->translate);

		if ($newFunc = $this->Contains($line, $keys))
		{
			$translatedFunc = $this->translate[$keys[$newFunc]];
			$translatedFunc = explode('|', $translatedFunc);

			$this->functions[] = $translatedFunc[0];
		}
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
		file_put_contents('translator/' . $this->outputFile, $template);
		echo ">> DONE\n\n";
	}
}