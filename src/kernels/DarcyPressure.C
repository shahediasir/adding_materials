#include "DarcyPressure.h"

template<>
InputParameters validParams<DarcyPressure>()
{
	// start with the parameters from our parent
	InputParameters params = validParams<Diffusion>();

	// Now add any extra parameters this class needs:
	// Add a required parameter. If this isn't provided in the input file MOOSE will error
	params.addParam<Real>("permeability", "The permibility (K) of the fluid");

	// Add a parameter with a default value. This valude can be overriden in the input file.
	params.addParam<Real>("viscosity", 7.98e-4, "The viscosity (mu) of the fluid. Default is for 30 degre C.");

	return params;
}

DarcyPressure::DarcyPressure(const InputParameters & parameters) : Diffusion(parameters),
		// get the parameters from the input file
		_permeability(getMaterialProperty<Real>("permeability")),
		_viscosity(getMaterialProperty<Real>("viscosity"))
{
}	// end of the constructor

DarcyPressure::~DarcyPressure()
{
}

Real
DarcyPressure::computeQpResidual()
{
	// K/mu * grad_u * grad_phi[i]
	return (_permeability[_qp]/_viscosity[_qp]) * Diffusion::computeQpResidual();
}

Real
DarcyPressure::computeQpJacobian()
{
	// K/mu * grad_phi[j] * grad_phi[i]
	return (_permeability[_qp]/_viscosity[_qp]) * Diffusion::computeQpJacobian();
}
