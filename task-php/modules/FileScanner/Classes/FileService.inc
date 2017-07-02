<?php

namespace modules\FileScanner\Classes;

class FileService {

  public function readFile($url, $candidates) {
    $candidate = array();
    try {
      $file = fopen($url, 'r');
      $columns = array();
      while (($line = fgetcsv($file)) !== FALSE) {
        $columns[] = $line;
        //$line is an array of the csv elements     
        $candidate[] = $this->parseLine($line, $candidates, $columns);
      }
      fclose($file);
      return $candidate;
    }
    catch (Exception $e) {
      $e->getMessage();

      return $candidate;
    }
  }

  //име и фамилия, пол ('f'/'m'), години, длъжност, за която кандидатства, 
  //години стаж по професията
  private function parseLine($line, $candidate, $columns) {
    $elements = $line;
    $candidates = array();

    if (isset($columns[1])) {
      //$username, $gender, $age, $job_position, $internship
      $candidate->setUserName($elements[0]);
      $candidate->setGender($elements[1]);
      $candidate->setAge($elements[2]);
      $candidate->setJobPosition($elements[3]);
      $candidate->setInternship($elements[4]);

      $candidates[$columns[0][0]] = $candidate->getFieldValue($columns[0][0]);
      $candidates[$columns[0][1]] = $candidate->getFieldValue($columns[0][1]);
      $candidates[$columns[0][2]] = $candidate->getFieldValue($columns[0][2]);
      $candidates[$columns[0][3]] = $candidate->getFieldValue($columns[0][3]);
      $candidates[$columns[0][4]] = $candidate->getFieldValue($columns[0][4]);      
    }

    return $candidates;
  }

}
