#ifndef PACKEDCOLUMN_H
#define PACKEDCOLUMN_H
	
#include "Material.h"

// A helper class from Moose that linear interpolates x,y data
//
#include "LinearInterpolation.h"

class PackedColumn;

template<>
InputParameters validParams<PackedColumn>();

/* Material objects inherit from Material and override computeQpProperties.
 *
 * Their job is to declare properties for use for use by other objects in the calculation such as 
 * Kernels and BoundaryConditions. */

class PackedColumn : public Material
{
public:
	PackedColumn (const InputParameters & parameters);

protected:
	/* Necessary override. This is where the values of the properties are computed */

	virtual void computeQpProperties() override;

	// The radius of the balls in the column
	
	const Real & _ball_radius;

	// Based on the paper 
	LinearInterpolation _permeability_interpolation;

	// The permeability (K)
	MaterialProperty<Real> & _permeability;

	// the viscosity of the fluid (mu)
	MaterialProperty<Real> & _viscosity;

};

#endif
