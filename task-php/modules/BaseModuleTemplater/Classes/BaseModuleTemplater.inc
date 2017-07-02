<?php
namespace modules\BaseModuleTemplater\Classes;
class BaseModuleTemplater{
  protected $properties;
  protected $path;
  
  function __construct($path) {
    $this->path = $path;
  }

  public function get($property) {      
      return $this->properties[$property];
  }

  public function set($property, $value) {    
    $this->properties[$property] = $value;     
  }
  
  public function publish(){
    require_once($this->path);
  }
}