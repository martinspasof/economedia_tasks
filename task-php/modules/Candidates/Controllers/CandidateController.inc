<?php

  $file_service = new modules\FileScanner\Classes\FileService();
  $url = './resource/candidates.job.csv';
  $candidates = new modules\Candidates\Classes\Candidate(array());
  $get_candidates_from_file = $file_service->readFile($url,$candidates);
  $get_candidates = array_filter($get_candidates_from_file);

           
  $stack = array();
  $stack['max_count'] = count($get_candidates);
  $stack['limit'] = 5;
  $utils = new modules\Utils\Classes\Utils(); 
  $paging = $utils->pagination($stack);
  $slice_get_candidates = array_slice($get_candidates,$paging['start'],$paging['limit']);

 $candidates_list = new modules\BaseModuleTemplater\Classes\BaseModuleTemplater(ROOT . '/modules/Candidates/tpl/candidates_list.tpl.inc'); 
 $candidates_list->set('slice_get_candidates', $slice_get_candidates);
 $candidates_list->set('paging', $paging);
 $candidates_list->publish();

