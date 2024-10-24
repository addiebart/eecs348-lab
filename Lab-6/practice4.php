<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="robots" content="noindex, nofollow, noarchive">
    <title>Practice 4</title>
</head>
<body>

    <?php
        $size = (integer) $_POST["size"];
        $size++;
        $html = "<table border=1><tbody>";
        for ($row = 0; $row < $size; $row++) {
            $html = $html . "<tr>";
            for ($col = 0; $col < $size; $col++) {
                $data = 0;
                if ($col == 0 and $row == 0) {
                    $html = $html . "<td> </td>";
                }
                else if ($row == 0) {
                    $data = $col;
                    $html = $html . "<td>" . (string) $data . "</td>"; 
                }
                else if ($col == 0) {
                    $data = $row;
                    $html = $html . "<td>" . (string) $data . "</td>"; 
                }
                else {
                    $data = $row * $col;
                    $html = $html . "<td>" . (string) $data . "</td>";
                }
            }
            $html = $html . "</tr>";
        }
        $html = $html . "</tbody></table>";
        echo $html;
    ?>

</body>
</html>