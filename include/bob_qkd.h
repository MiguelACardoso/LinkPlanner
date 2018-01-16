#ifndef BOB_QKD_H_
#define BOB_QKD_H

#include "netxpto.h"
#include "binary_mapper.h"
#include "discrete_to_continuous_time.h"
#include "pulse_shaper_20180111.h"
#include "super_block_interface.h"
#include "fork_20180112.h"

class BobQKD : public SuperBlock {

	// #####################################################################################################
	// ################## Internal Signals Declaration and Inicialization ##################################
	// #####################################################################################################
	TimeDiscreteAmplitudeDiscreteReal S1{ "Bob_1.sgn" };
	TimeContinuousAmplitudeDiscreteReal S2{ "Bob_2.sgn" };
	TimeContinuousAmplitudeDiscreteReal S3{ "SB4.sgn" };
	TimeContinuousAmplitudeDiscreteReal S4{ "S4.sgn" };
	TimeContinuousAmplitudeDiscreteReal S5{ "Bob_3.sgn" };
	TimeContinuousAmplitudeDiscreteReal S6{ "CLKB_1.sgn" };
	TimeContinuousAmplitudeDiscreteReal S7{ "CLKB_2.sgn" };
	TimeContinuousAmplitudeDiscreteReal S8{ };
	TimeContinuousAmplitudeDiscreteReal S9{ };

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################
	BinaryMapper BB0;
	DiscreteToContinuousTime BB1;
	PulseShaper BB2;

	PulseShaper BB3;
	Fork BB4;

	SuperBlockInterface BB9;


public:
	/* input parameters*/


	BobQKD(vector <Signal*> &inputSignals, vector <Signal*> &outputSignals);

	void setNumberOfSamplesPerSymbol(int n) { BB1.setNumberOfSamplesPerSymbol(n); };
	int const getNumberOfSamplesPerSymbol(void) { return BB1.getNumberOfSamplesPerSymbol(); };

	void setSeeBeginningOfImpulseResponse(bool sBeginningOfImpulseResponse) { BB2.setSeeBeginningOfImpulseResponse(sBeginningOfImpulseResponse); };
	double const getSeeBeginningOfImpulseResponse(void) { return BB2.getSeeBeginningOfImpulseResponse(); };

	void setPulseShaperFilter(PulseShaperFilter fType) { BB2.setFilterType(fType); BB3.setFilterType(fType); };

	void setPulseWidth(double tWidth) { BB3.setPulseWidth(tWidth); };
	double getPulseWidth() { return BB3.getPulseWidth(); };

	void setPulseDelay(double pDelay) { BB3.setPulseDelay(pDelay); };
	double getPulseDelay() { return BB3.getPulseDelay(); };

};

#endif