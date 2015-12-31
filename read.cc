... include header files ...

const Event* read( std::ifstream& file ) {

  Event* ev;
  int i;
  // try to read input file
  ...

  // read number of points
  ...

  // read and store energy loss
  ...

  return ev;

}

