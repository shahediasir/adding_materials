#include "HeatCondRafiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

//Kernels
#include "DarcyPressure.h"  // you have to add this into the header file

// Materials
#include "PackedColumn.h"

template<>
InputParameters validParams<HeatCondRafiApp>()
{
	InputParameters params = validParams<MooseApp>();
	params.set<bool>("use_legacy_uo_initialization") = false;
	params.set<bool>("use_legacy_uo_aux_computation") = false;
	
	return params;
}

HeatCondRafiApp::HeatCondRafiApp(InputParameters parameters):
	MooseApp(parameters)
{
	Moose::registerObjects(_factory);
	ModulesApp::registerObjects(_factory);
	HeatCondRafiApp::registerObjects(_factory);

	Moose::associateSyntax(_syntax, _action_factory);
	ModulesApp::associateSyntax(_syntax, _action_factory);
	HeatCondRafiApp::associateSyntax(_syntax, _action_factory);
}

HeatCondRafiApp::~HeatCondRafiApp()
{
}

void
HeatCondRafiApp::registerApps()
{
	registerApp(HeatCondRafiApp);
}

void 
HeatCondRafiApp::registerObjects(Factory & factory)
{
	registerKernel(DarcyPressure);
	registerMaterial(PackedColumn);
} //  

void
HeatCondRafiApp::associateSyntax(Syntax & /*syntax */, ActionFactory & /*action_factory*/)
{
}










