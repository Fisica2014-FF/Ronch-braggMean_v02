... include header files ...

BraggStatistic::BraggStatistic( int minEnergy, int maxEnergy ):
  // initializations
  ... {
  // allocate arrays for sums, mean and rms: set size at min number of points
  ...
  // set at 0 all sums, means and rms
  ...
}


BraggStatistic::~BraggStatistic() {
  // free dynamic memory
  ...
}


void BraggStatistic::add( const Event* ev ) {

  // loop over the min number of points and compute total energy
  ...

  // check for total energy being in the required range,
  // if not return
  ...

  // loop over points and update sums for each point
  ...

  // update event counter
  ...

  return;

}


const float* BraggStatistic::eMean() const {
  ...
}


const float* BraggStatistic::eRMS()  const {
  ...
}


void BraggStatistic::compute() {
  // loop over points and compute mean and rms for each point
  ...
  return;
}

