<?php

class NightsWatch implements IFighter {
  private $fighters = array();

  public function recruit($member) {
    $this->fighters[] = $member;
  }

  function fight() {
    foreach ($this->fighters as $value) {
      if (method_exists($value, "fight")) {
        $value->fight();
      }
    }
  }
}

?>