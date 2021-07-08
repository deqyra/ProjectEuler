# Folders
$scriptFolder = Split-Path $MyInvocation.MyCommand.Path -Parent
$repoRoot = Split-Path $scriptFolder -Parent
$solutionRoot = Join-Path $repoRoot 'solutions/'

# Find the last solved problem number
$solutions = Get-ChildItem -Path $solutionRoot
$oldIndex = ($solutions.count).ToString()
$newIndex = ($solutions.count + 1).ToString()

# Pad indices with as many 0's as required to make them 4 digits long
for (; -Not ($oldIndex.Length -eq 4);) {
    $oldIndex = '0' + $oldIndex
}
for (; -Not ($newIndex.Length -eq 4);) {
    $newIndex = '0' + $newIndex
}

# Create folder for new solution
$newSolutionRoot = Join-Path $solutionRoot $newIndex
New-Item -Path $newSolutionRoot -ItemType Directory

$templateFolder = Join-Path $scriptFolder 'template/'

# Create header file from template
$templateHeaderFile = Join-Path $templateFolder 'main.hpp'
$headerContents = Get-Content $templateHeaderFile
$headerContents = $headerContents.Replace('XXXX', $newIndex)
$newHeaderFile = Join-Path $newSolutionRoot 'main.hpp'
Set-Content -Path $newHeaderFile -Value $headerContents

# Create source file from template
$templateSourceFile = Join-Path $templateFolder 'main.cpp'
$sourceContents = Get-Content $templateSourceFile
$newSourceFile = Join-Path $newSolutionRoot 'main.cpp'
Set-Content -Path $newSourceFile -Value $sourceContents

# Create CMakeLists.txt from template
$templateCMakeFile = Join-Path $templateFolder 'CMakeLists.txt'
$CMakeFileContents = Get-Content $templateCMakeFile
$CMakeFileContents = $CMakeFileContents.Replace('XXXX', $newIndex)
$newCMakeFile = Join-Path $newSolutionRoot 'CMakeLists.txt'
Set-Content -Path $newCMakeFile -Value $CMakeFileContents

$mainCMakeFile = Join-Path $repoRoot 'CMakeLists.txt'
$mainCMakeFileContents = Get-Content $mainCMakeFile

# Get commmand template
$templateCommandFile = Join-Path $templateFolder 'cmake_subdir_command.cmake'
$templateCommand = Get-Content $templateCommandFile
$templateCommand = $templateCommand.Replace('XXXX', $newIndex)

# Append command to main CMakeLists.txt
$mainCMakeFileContents = $mainCMakeFileContents + $templateCommand
$previousTarget = 'ProjectEuler' + $oldIndex
$newTarget = 'ProjectEuler' + $newIndex
$mainCMakeFileContents = $mainCMakeFileContents.Replace($previousTarget, $newTarget)
Set-Content -Path $mainCMakeFile -Value $mainCMakeFileContents
