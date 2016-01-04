#include "Event.h"

// set the min (120) and max (128) number of points
...

Event::Event( int n ):
  // initializations
  ... {
  // allocate array to contain energies: set size at max number of points
  ...
}


Event::~Event() {
  // free dynamic memory
  ...
}


void Event::add( int energyLoss ) {
  // check for max array size:
  // if max number of points not yet reached
  //   increase number of points and store new point energy
  // if max number of points already reached
  //   do nothing
  ...
}


int Event::eventNumber() const {
  ...
}


unsigned int Event::dataSize() const {
  ...
}


int Event::energy( unsigned int i ) const {
  // check for required point being inside the array:
  // - if required point inside the array return its energy
  // - if not return -1
  ...
  return -1;
}


unsigned int Event::maxSize() {
  return sMax;
}


unsigned int Event::minSize() {
  return sMin;
}

