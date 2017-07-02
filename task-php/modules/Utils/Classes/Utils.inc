<?php

namespace modules\Utils\Classes;

class Utils {

  public function pagination($stack = array()) {

    $max_count = $stack['max_count'];
    $limit = $stack['limit'];
    if (isset($_GET['page']) && (int) $_GET['page'] > 0) {
      $page = (int) $_GET['page'];
    }
    else {
      $page = 1;
    }
    $max_pages = ceil($max_count / $limit);
    $get_limit_page = $limit * $page;

    $start = $get_limit_page - $limit;
    $row = $start + 1;

    $stack['page'] = $page;
    $stack['max_pages'] = $max_pages;
    $stack['row'] = $row;
    $stack['start'] = $start;

    return $stack;
  }

}
