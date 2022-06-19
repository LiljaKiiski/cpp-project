//Catch receiver signals
void translateIR(){
  switch(results.value){
    case 0xFF629D: //VOL+ - Forward
      run_forward();
      break;
    
    case 0xFF22DD: //FAST BACK - Turn left
      turn_left();
      break;
    
    case 0xFF02FD: //PAUSE - Stop car from moving
      run_stop();
      break;
    
    case 0xFFC23D: //FAST FORWARD - Turn right
      turn_right();
      break;
    
    case 0xFFA857: //VOL- - Backward
      run_backward();
      break;
  }
}
