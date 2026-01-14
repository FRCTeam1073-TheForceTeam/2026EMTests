// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TestCommand.h"
#include <frc/smartdashboard/SmartDashboard.h>

TestCommand::TestCommand(std::shared_ptr<TestMechanism> subsys)
    : m_subsystem{subsys} {
  // Register that this command requires the subsystem.
  AddRequirements(m_subsystem.get());

    // Set up our initial widget value:
    frc::SmartDashboard::PutNumber("TestCommand", 0.0);
  }

  void TestCommand::Initialize() {
    m_subsystem->SetCoastMode(true);
  }

  void TestCommand::Execute()  {

    // Read the widget value and send to hardware:
    auto value = units::velocity::meters_per_second_t(frc::SmartDashboard::GetNumber("TestCommand", 0.0));
    m_subsystem->SetCommand(value);
  
    
  }

 
  bool TestCommand::IsFinished()  {
    return false; // run forever.
  }