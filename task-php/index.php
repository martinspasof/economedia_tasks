<?php 
define('ROOT', dirname($_SERVER['SCRIPT_FILENAME']));
$WEB_ROOT = "http://" . $_SERVER['HTTP_HOST'] . dirname($_SERVER['PHP_SELF']) . "/";
define('WEB_ROOT', $WEB_ROOT);
header('Access-Control-Allow-Methods: GET, POST');
header("Access-Control-Allow-Headers: X-Requested-With");
include ROOT . '/html/header.inc';
require_once("./AutoLoader.inc");
        
include ROOT . '/modules/Candidates/Controllers/CandidateController.inc';        
include ROOT . '/html/footer.inc';