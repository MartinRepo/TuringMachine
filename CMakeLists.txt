cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled Main.cpp TuringMachine.h TuringMachineState.h DenseTuringMachine.h TuringTape.h SparseTuringMachine.h MenuSystem.h TuringMachineState.cpp DenseTuringMachine.cpp TuringTape.cpp MenuSystem.cpp SparseTuringMachine.cpp)
