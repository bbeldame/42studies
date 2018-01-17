<?php

class Targaryen {
  public function getBurned() {
    if (method_exists($this, 'resistsFire') && $this->resistsFire()){
      return ("emerges naked but unharmed");
    } else {
      return ("burns alive");
    }
  }
}

?>