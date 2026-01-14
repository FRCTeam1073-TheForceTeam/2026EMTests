// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <memory>

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/TestMechanism.h"

/**
 * This example command uses dashboard widgets to command the example
 * subsystem in various ways.
 */
class TestCommand
    : public frc2::CommandHelper<frc2::Command, TestCommand> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsys The subsystem used by this command.
   */
  explicit TestCommand(std::shared_ptr<TestMechanism> subsys);

  void Initialize() override;

   /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Execute() override;

  /**
   * Called to see if test command is done... it runs forever.
   */
  bool IsFinished() override;

 private:
  std::shared_ptr<TestMechanism> m_subsystem;
};
