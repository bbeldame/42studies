<?php

class UnholyFactory {
  private $absorbedClasses = array();

  public function absorb($undead) {
    if (!in_array($undead->type, $this->absorbedClasses)) {
      if ($undead->isFighter) {
        echo "(Factory absorbed a fighter of type $undead->type)" . PHP_EOL;
        $this->absorbedClasses[] = $undead->type;
      } else {
        echo "(Factory can't absorb this, it's not a fighter)" . PHP_EOL;
      }
    } else {
      echo "(Factory already absorbed a fighter of type $undead->type)" . PHP_EOL;
    }
  }

  public function fabricate($type) {
    if (in_array($type, $this->absorbedClasses)) {
      echo "(Factory fabricates a fighter of type $type)" . PHP_EOL;
      $className = str_replace(" ", "", $type);
      $className = ucfirst($className);
      return new $className();
    } else {
      echo "(Factory hasn't absorbed any fighter of type $type)" . PHP_EOL;
    }
  }
}

?>