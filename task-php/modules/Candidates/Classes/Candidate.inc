<?php

namespace modules\Candidates\Classes;

class Candidate {

  private static $username = "Username";
  private static $gender = "Gender";
  private static $age = "Age";
  private static $job_position = "JobPosition";
  private static $internship = "Internship";
  private static $selectedColumn = '';


  function __construct($stack = array()) {
    $username = isset($stack['username']) ? $stack['username'] : '';
    $gender = isset($stack['gender']) ? $stack['gender'] : '';
    $age = isset($stack['age']) ? $stack['age'] : '';
    $job_position = isset($stack['job_position']) ? $stack['job_position'] : '';
    $internship = isset($stack['internship']) ? $stack['internship'] : '';

    $this->username = $username;
    $this->gender = $gender;
    $this->age = $age;
    $this->job_position = $job_position;
    $this->internship = $internship;
  }

  public function getFieldValue($selectedColumn) {

    $this->selectedColumn = $selectedColumn;

    switch ($this->selectedColumn) {
      case "username" : return $this->getUserName();
      case "gender" : return $this->getGender();
      case "age" : return $this->getAge();
      case "job_position" : return $this->getJobPosition();
      case "internship" : return $this->getInternship();
      default: return null;
    }
  }

  public function getUserName() {
    return $this->username;
  }

  public function setUserName($username) {
    $this->username = $username;
  }

  public function getGender() {  
    return $this->gender;
  }

  public function setGender($gender) {    
    $this->gender = $gender;    
  }

  public function getAge() {
    return $this->age;
  }

  public function setAge($age) {
    $this->age = $age;
  }

  public function getJobPosition() {    
    return $this->job_position;
  }

  public function setJobPosition($job_position) {
    return $this->job_position = $job_position;
  }

  public function getInternship() {
    return $this->internship;
  }

  public function setInternship($internship) {
    return $this->internship = $internship;
  }


}
