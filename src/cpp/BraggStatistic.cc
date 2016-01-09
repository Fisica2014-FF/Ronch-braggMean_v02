//... include header files ...

#include "../BraggStatistic.h"

#include <cmath>

BraggStatistic::BraggStatistic(int minEnergy, int maxEnergy) :
		MIN_ENERGY_(minEnergy), MAX_ENERGY_(maxEnergy), number_of_events_(0), sumenergies(
				new int[Event::maxSize()]), sumsquares(
				new unsigned[Event::maxSize()]), meanenergies(
				new double[Event::maxSize()]), rmsenergies(
				new double[Event::maxSize()]) {
	// TODO scott meyers inizialization
	// allocate arrays for sums, mean and rms: set size at min number of points
	//...

	// set at 0 all sums, means and rms
	for (unsigned i = 0; i < Event::maxSize(); ++i) {
		sumenergies[i] = 0;
		sumsquares[i] = 0;
		meanenergies[i] = 0;
		rmsenergies[i] = 0;
	}
}

BraggStatistic::~BraggStatistic() {
	delete[] sumenergies;
	delete[] sumsquares;
	delete[] meanenergies;
	delete[] rmsenergies;
}

// Corrected an incongruence: a Event* here and an Event& in
// the header BraggStatistic.h
// I suppose it was intended to be a Event&
// void BraggStatistic::add( const Event* ev ) {
void BraggStatistic::add(const Event& ev) {

	// loop over the min number of points and compute total energy
	long totalenergy = 0;
	for (unsigned i = 0; i < Event::minSize(); ++i) {
		totalenergy += ev.energy(i);
	}

	// check for total energy being in the required range,
	// if not return
	if (!(totalenergy > MIN_ENERGY_ and totalenergy < MAX_ENERGY_)) {
		return;
	}

	// loop over points and update sums for each point
	for (unsigned i = 0; i < Event::minSize(); ++i) {
		sumenergies[i] += ev.energy(i);
		sumsquares[i] += (ev.energy(i) * ev.energy(i));
	}

	// update event counter
	++number_of_events_;

	return;

}

//TODO messo un double al posto del float
const double* BraggStatistic::eMean() const {
	return meanenergies;
}

const double* BraggStatistic::eRMS() const {
	return rmsenergies;
}

void BraggStatistic::compute() {
	// loop over points and compute mean and rms for each point
	//For every point, calculate the mean and rms
	for (unsigned i = 0; i < Event::minSize(); ++i) {
		meanenergies[i] = sumenergies[i] / double(number_of_events_);
		rmsenergies[i] = std::sqrt(sumsquares[i] / double(number_of_events_));
	}
	return;
}

