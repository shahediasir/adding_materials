[Mesh]
    type = GeneratedMesh
    dim = 2
    nx = 1000  #10 thousands
    ny = 500  #1 thounds
    xmax = 1    #length in m
    ymax = 0.5  #width in m
[]

[Variables]
    [./pressure]
    [../]
[]

[Kernels]
    [./darcy_pressure]
        type = DarcyPressure   # have to have a source and header file
        variable = pressure
        # no paramers needed becaue the value will come from the material system
    [../]
[]

[BCs]
    [./inlet]
        type = DirichletBC
        variable = pressure 
        boundary= left # this "left" may be came from the mesh
        value = 4000 # (pa) From Figure 2 from paper. First data point for 1mm balls
    [../]
    [./outlet]
        type = DirichletBC
        variable = pressure
        boundary = right
        value = 0 # (Pa)
    [../]

[Materials]
    [./column]       # have to read about this 
        type = PackedColumn # may be need a source and header file
        block = 0
        ball_radius = 1
    [../]
[]

[Problem]
    type = FEProblem
    coord_type = RZ
    rz_coord_axis = x
[]

[Executioner]
    type = Steady
    solve_type = PJFNK
    petsc_options_iname = '-pc_type -pc_hypre_type'
    petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
    exodus = true
[]



























