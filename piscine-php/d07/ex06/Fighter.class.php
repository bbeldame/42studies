<?php

abstract class Fighter {
  public $type;
  public $isFighter = true;
  abstract protected function fight($target);

  public function __construct($type) {
    $this->type = $type;
  }
}

?>