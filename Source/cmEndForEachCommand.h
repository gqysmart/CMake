/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmEndForEachCommand_h
#define cmEndForEachCommand_h

#include "cmCommand.h"

/** \class cmEndForEachCommand
 * \brief ends an if block
 *
 * cmEndForEachCommand ends an if block
 */
class cmEndForEachCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  cmCommand* Clone() CM_OVERRIDE { return new cmEndForEachCommand; }

  /**
   * Override cmCommand::InvokeInitialPass to get arguments before
   * expansion.
   */
  bool InvokeInitialPass(std::vector<cmListFileArgument> const&,
                         cmExecutionStatus&) CM_OVERRIDE;

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  bool InitialPass(std::vector<std::string> const&,
                   cmExecutionStatus&) CM_OVERRIDE
  {
    return false;
  }

  /**
   * This determines if the command is invoked when in script mode.
   */
  bool IsScriptable() const CM_OVERRIDE { return true; }

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  std::string GetName() const CM_OVERRIDE { return "endforeach"; }

  cmTypeMacro(cmEndForEachCommand, cmCommand);
};

#endif
