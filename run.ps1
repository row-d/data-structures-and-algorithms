$folderpath = Get-Location
$archivosFuente = Get-ChildItem -Path $folderpath -Filter "*.cpp"
$command = "clang++ -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic"
foreach ($archivo in $archivosFuente) {
    $command += " $($archivo.FullName)"
}

Invoke-Expression $command