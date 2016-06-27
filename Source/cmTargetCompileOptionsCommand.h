/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2013 Stephen Kelly <steveire@gmail.com>

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/

#ifndef cmTargetCompileOptionsCommand_h
#define cmTargetCompileOptionsCommand_h

#include "cmTargetPropCommandBase.h"

class cmTargetCompileOptionsCommand : public cmTargetPropCommandBase
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  cmCommand* Clone() CM_OVERRIDE { return new cmTargetCompileOptionsCommand; }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  bool InitialPass(std::vector<std::string> const& args,
                   cmExecutionStatus& status) CM_OVERRIDE;

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  std::string GetName() const CM_OVERRIDE { return "target_compile_options"; }

  cmTypeMacro(cmTargetCompileOptionsCommand, cmTargetPropCommandBase);

private:
  void HandleImportedTarget(const std::string& tgt) CM_OVERRIDE;
  void HandleMissingTarget(const std::string& name) CM_OVERRIDE;

  bool HandleDirectContent(cmTarget* tgt,
                           const std::vector<std::string>& content,
                           bool prepend, bool system) CM_OVERRIDE;
  std::string Join(const std::vector<std::string>& content) CM_OVERRIDE;
};

#endif
