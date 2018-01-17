<?php

class Lannister {
  public function sleepWith($partner) {
    if (get_parent_class($partner) !== "Lannister") {
      echo "Let's do this." . PHP_EOL;
    } else if ($this->okWithIncest && !$partner->notOk) {
      echo "With pleasure, but only in a tower in Winterfell, then." . PHP_EOL;
    } else {
      echo "Not even if I'm drunk !" . PHP_EOL;
    }
  }
}

?>