# Folders
$scriptFolder = Split-Path $MyInvocation.MyCommand.Path -Parent
$repoRoot = Split-Path $scriptFolder -Parent
$solutionRoot = Join-Path $repoRoot 'solutions/'

# Find the last solved problem number
$solutions = Get-ChildItem -Path $solutionRoot
$oldIndex = ($solutions.count - 1).ToString()
$newIndex = ($solutions.count).ToString()

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
$headerContents = $headerContents.Replace('YYYY', $solutions.count)
$newHeaderFile = Join-Path $newSolutionRoot 'main.hpp'
Set-Content -Path $newHeaderFile -Value $headerContents

# Create source file from template
$templateSourceFile = Join-Path $templateFolder 'main.cpp'
$sourceContents = Get-Content $templateSourceFile
$sourceContents = $sourceContents.Replace('XXXX', $newIndex)
$sourceContents = $sourceContents.Replace('YYYY', $solutions.count)
$newSourceFile = Join-Path $newSolutionRoot 'main.cpp'
Set-Content -Path $newSourceFile -Value $sourceContents

# Create CMakeLists.txt from template
$templateCMakeFile = Join-Path $templateFolder 'CMakeLists.txt'
$CMakeFileContents = Get-Content $templateCMakeFile
$CMakeFileContents = $CMakeFileContents.Replace('XXXX', $newIndex)
$CMakeFileContents = $CMakeFileContents.Replace('YYYY', $solutions.count)
$newCMakeFile = Join-Path $newSolutionRoot 'CMakeLists.txt'
Set-Content -Path $newCMakeFile -Value $CMakeFileContents

$mainCMakeFile = Join-Path $repoRoot 'CMakeLists.txt'
$mainCMakeFileContents = Get-Content $mainCMakeFile

# Get commmand template
$templateCommandFile = Join-Path $templateFolder 'cmake_subdir_command.cmake'
$templateCommand = Get-Content $templateCommandFile
$templateCommand = $templateCommand.Replace('XXXX', $newIndex)
$templateCommand = $templateCommand.Replace('YYYY', $solutions.count)

# Append command to main CMakeLists.txt
$mainCMakeFileContents = $mainCMakeFileContents + $templateCommand
$previousTarget = 'ProjectEuler' + $oldIndex
$newTarget = 'ProjectEuler' + $newIndex
$mainCMakeFileContents = $mainCMakeFileContents.Replace($previousTarget, $newTarget)
Set-Content -Path $mainCMakeFile -Value $mainCMakeFileContents

# Update solved count in README.md
$readmeFile = Join-Path $repoRoot 'README.md'
$readmeContents = Get-Content $readmeFile
$readmeContents = $readmeContents.Replace(($solutions.count - 2).ToString() + " / 760", ($solutions.count - 1).ToString() + " / 760")
Set-Content -Path $readmeFile -Value $readmeContents
