# Folders
$scriptFolder = Split-Path $MyInvocation.MyCommand.Path -Parent
$repoRoot = Split-Path $scriptFolder -Parent
$solutionRoot = Join-Path $repoRoot 'solutions/'

# Find the last solved problem number
$solutions = Get-ChildItem -Path $solutionRoot
$lastIndex = ($solutions.count).ToString()

# Pad index with as many 0's as required to make it 4 digits long
for (; -Not ($lastIndex.Length -eq 4);) {
    $lastIndex = '0' + $lastIndex
}

# Ensure CMake has run the generation step
$buildFolder = Join-Path $repoRoot 'build'
$buildFolderExists = Test-Path $buildFolder
if (-Not $buildFolderExists) {
    New-Item -Path $buildFolder -ItemType Directory
}

Push-Location $buildFolder

# Compose the commands
$target = 'ProjectEuler' + $lastIndex
$cmakeGenerateCommand = 'cmake ..'
$cmakeBuildCommand = 'cmake --build . --target copy_latest ' + $target

# Execute the commands
Invoke-Expression $cmakeGenerateCommand
Invoke-Expression $cmakeBuildCommand

Pop-Location
