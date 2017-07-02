<?php

class AutoLoader {

 public static function loadClass($className) {
        $fileName = '';
        $namespace = '';

        // Sets the include path as the "src" directory
        $includePath = dirname(__FILE__).DIRECTORY_SEPARATOR;
  
        if (false !== ($lastNsPos = strripos($className, '\\'))) {
            $namespace = substr($className, 0, $lastNsPos);
            $className = substr($className, $lastNsPos + 1);
            $fileName = str_replace('\\', DIRECTORY_SEPARATOR, $namespace) . DIRECTORY_SEPARATOR;
               
        }
        $fileName .= str_replace('_', DIRECTORY_SEPARATOR, $className) . '.inc';
        $fullFileName = $includePath . DIRECTORY_SEPARATOR . $fileName;
 
        if (file_exists($fullFileName)) {
            require $fullFileName;
        } else {
            echo 'Class "'.$className.'" does not exist.';
        }
    }
   
}

 spl_autoload_register('AutoLoader::loadClass'); // Registers the autoloader