# Ensure that you are in the right directory (where the source files are located)
$projectDir = "C:\Users\josht\Documents\raylib test2"
$projectDir

# Set the output file name
$outputExe = "TetrisGame.exe"

# Define the source files
$sourceFiles = "main.cpp Game.cpp Board.cpp Tetrominoes.cpp raylibCpp.cpp"

# Set the compiler options and libraries for raylib
$compiler = "g++"
$options = "-std=c++17 -Wall"
$raylibLibraries = "-lraylib -lopengl32 -lgdi32 -lwinmm"

# Command to compile the program
$compileCommand = "$compiler $options $sourceFiles -o $outputExe $raylibLibraries"

# Execute the compile command
Write-Host "Compiling..."
Invoke-Expression $compileCommand

# Check if the .exe was successfully created
if (Test-Path $outputExe) {
    Write-Host "$outputExe has been successfully created!"
} else {
    Write-Host "Compilation failed. Please check for errors."
}
