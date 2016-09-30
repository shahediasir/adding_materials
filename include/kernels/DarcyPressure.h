#ifndef DARCYPRESSURE_H
#define DARCYPRESSURE_H

// Including the "Diffusion" kernel here so we can extend it
// it is the same equaiton with mulitplying some constant

#include "Diffusion.h"

class DarcyPressure;	// defining the class

template<>
InputParameters validParams<DarcyPressure>();

/* Represents K/mu * grad_u * grad*phi
 * we are inheriting from Diffusion instead of from Kernel because the grad_u* grad_phi is already coded in 
 * there and all we need to do is specialize that calculation by multiplying by k/mu */

class DarcyPressure : public Diffusion	
{
public:
	DarcyPressure(const InputParameters & parameters);	// constructor
	virtual ~DarcyPressure();	// deconstructor

protected:
	/* kernels _must_override computeQpResidual() */

	virtual Real computeQpResidual() override;		// this override is a new thing , I don't know what it do// does

	/* This is optional (but recommended !) */

	virtual Real computeQpJacobian() override;




	// will be set from the input file
	// Real _permeability;  this values will be taken care of from the material package
	// Real _viscosity;     also from the material package 
	/* These references will be set by the initialization list so that values can be pulled from the 
		material system */

	const MaterialProperty<Real> & _permeability;
	const MaterialProperty<Real> & _viscosity; 

};

#endif
