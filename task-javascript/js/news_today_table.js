function createTableNewsToday(news_data) {
    var myTable = "<table id='myTable' class='table'><thead><tr><th style='width: 100px; color: red;'>#</th>";
    myTable += "<th style='width: 2px; color: red;'>Image</th>";
    myTable += "<th style='width: 100px; color: red;'>Title</th>";
    myTable += "<th style='width: 100px; color: red;'>Description</th>";
    myTable += "<th style='width: 100px; color: red;' onclick=\"sortTable(4,false)\">Date</th>"
    myTable += "<th style='width: 100px; color: red;' onclick=\"sortTable(5,false)\">Author</th>";
    myTable += "<th style='width: 100px; color: red;' onclick=\"sortTable(6,true)\">Count of comments</th>";
    myTable += "<th style='width: 100px; color: red;'>Address to Issue</th></tr>";
    myTable += "</thead><tbody>";

    var row = 0;
    for (index = 0; index < news_data.length; index++) {
        if ((news_data[index]['img_src'] === undefined) || (news_data[index]['author'] === '') || (news_data[index]['count_comments'] === '')) {
            continue;
        }
        myTable += "<tr><td style='width: 100px;'><div style='width: 2px;'>" + (++row) + "</div></td>";
        myTable += "<td style='width: 100px;'><img style='width:220px;' src=" + news_data[index]['img_src'] + " alt=" + news_data[index]['title'] + "></td>";
        myTable += "<td style='width: 100px;'>" + news_data[index]['title'] + "</td>";
        myTable += "<td style='width: 100px;'>" + news_data[index]['description'] + "</td>";
        myTable += "<td style='width: 100px;'>" + news_data[index]['date'] + "</td>";
        myTable += "<td style='width: 100px;'>" + news_data[index]['author'] + "</td>";
        myTable += "<td style='width: 100px;'><div style='width: 120px;'>" + news_data[index]['count_comments'] + "</div></td>";
        myTable += "<td style='width: 100px;'><div style='width: 120px;word-break: break-all' >" + news_data[index]['link'] + "</div></td></tr>";

    }


    myTable += "</tbody></table>";

    document.getElementById("news_data").innerHTML = myTable;
}

function sortTable(cellNumber, isNumber) {
    var table, rows, switching, i, x, y, shouldSwitch;
    table = document.getElementById("myTable");
    switching = true;
    /*Make a loop that will continue until
     no switching has been done:*/
    while (switching) {
        //start by saying: no switching is done:
        switching = false;
        rows = table.getElementsByTagName("TR");
        /*Loop through all table rows (except the
         first, which contains table headers):*/
        for (i = 1; i < (rows.length - 1); i++) {
            //start by saying there should be no switching:
            shouldSwitch = false;
            /*Get the two elements you want to compare,
             one from current row and one from the next:*/
            x = rows[i].getElementsByTagName("TD")[cellNumber];
            y = rows[i + 1].getElementsByTagName("TD")[cellNumber];

            if (isNumber) {
                //check if the two rows should switch place:
                if (parseInt(x.innerText.toLowerCase()) > parseInt(y.innerText.toLowerCase())) {
                    //if so, mark as a switch and break the loop:
                    shouldSwitch = true;
                    break;
                }
            }else{
                //check if the two rows should switch place:
                if (x.innerText.toLowerCase() > y.innerText.toLowerCase()) {
                    //if so, mark as a switch and break the loop:
                    shouldSwitch = true;
                    break;
                }
            }
        }
        if (shouldSwitch) {
            /*If a switch has been marked, make the switch
             and mark that a switch has been done:*/
            rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
            switching = true;
        }
    }
}