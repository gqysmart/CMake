/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2004-2009 Kitware, Inc.
  Copyright 2013 Alexander Neundorf (neundorf@kde.org)

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmExtraKateGenerator_h
#define cmExtraKateGenerator_h

#include "cmExternalMakefileProjectGenerator.h"

class cmLocalGenerator;
class cmGeneratedFileStream;

/** \class cmExtraKateGenerator
 * \brief Write Kate project files for Makefile or ninja based projects
 */
class cmExtraKateGenerator : public cmExternalMakefileProjectGenerator
{
public:
  cmExtraKateGenerator();

  static cmExternalMakefileProjectGeneratorFactory* GetFactory();

  void Generate() CM_OVERRIDE;

private:
  void CreateKateProjectFile(const cmLocalGenerator* lg) const;
  void CreateDummyKateProjectFile(const cmLocalGenerator* lg) const;
  void WriteTargets(const cmLocalGenerator* lg,
                    cmGeneratedFileStream& fout) const;
  void AppendTarget(cmGeneratedFileStream& fout, const std::string& target,
                    const std::string& make, const std::string& makeArgs,
                    const std::string& path, const char* homeOutputDir) const;

  std::string GenerateFilesString(const cmLocalGenerator* lg) const;
  std::string GetPathBasename(const std::string& path) const;
  std::string GenerateProjectName(const std::string& name,
                                  const std::string& type,
                                  const std::string& path) const;

  std::string ProjectName;
  bool UseNinja;
};

#endif
