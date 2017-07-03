<?php
header('Access-Control-Allow-Origin: *');
define('ROOT', dirname($_SERVER['SCRIPT_FILENAME']));
$WEB_ROOT = "http://" . $_SERVER['HTTP_HOST'] . dirname($_SERVER['PHP_SELF']) . "/";
define('WEB_ROOT', $WEB_ROOT);

include ROOT . '/html/header.inc';
?>
<div id="news_data" class="container"></div> 
<script>

  var xhr = new XMLHttpRequest(),
          method = "GET",
          url = "//www.dnevnik.bg/allnews/today/";

  xhr.open(method, url, true);

  xhr.onreadystatechange = function () {
      if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
          var parser = new DOMParser();
          var doc = parser.parseFromString(xhr.responseText, "text/html");
          article = doc.getElementsByTagName("article");

          var news_today_content = new Array();


          for (i = 0; i < article.length; i++) {
              var news_today = {};
              /*
               * 0:text
               * 1:figure
               * 2:text
               * 3:div.text
               * 4:text 
               */
              var text0 = article[i].childNodes[0];
              var text2 = article[i].childNodes[2];

              var link = '';
              var title = '';
              var description = '';
              var img_src = '';
              var date = '';
              var author = '';
              var count_comments = '';

              try {
                  if (text0.nextElementSibling.localName === "figure") {
                      //childNodes[1]=span.thumbnail,childNodes[0]=text,NextElementSibling = a tag;attributes[0] = href property;attributes[1] = title 
                      link = text0.nextElementSibling.childNodes[1].childNodes[0].nextElementSibling.attributes[0].nodeValue;
                      title = text0.nextElementSibling.childNodes[1].childNodes[0].nextElementSibling.attributes[1].nodeValue;
                      // attributes[0]=img
                      img_src = text0.nextElementSibling.childNodes[1].childNodes[2]
                              .parentElement.childNodes[1].lastElementChild
                              .attributes[0].nodeValue;
                  }

                  var get_key_article_tools = (text2.nextElementSibling.childNodes[5].className === 'article-tools') ? 5 : 7;

                  //childNodes[1]=time;childNodes[5].className = 'article-tools'
                  date = text2.nextElementSibling.childNodes[get_key_article_tools].childNodes[1].innerText;

                  //childNodes[3] = link and text the name author,childNodes[0]=text
                  author = text2.nextElementSibling.childNodes[get_key_article_tools].childNodes[3].childNodes[0].nodeValue;

                  //childNodes[5]=div.article-tools,parentNode=div.text;ownerElement=div.text,childNodes[3]=p(paragraph);innerHTML(innerText) = description
                  description = text2.nextElementSibling.childNodes[get_key_article_tools].nextSibling.parentNode.attributes[0].ownerElement.childNodes[3].innerText;

                  // the second value childNodes[5] = "a" element 
                  if (text2.nextElementSibling.childNodes[5].childNodes[get_key_article_tools].childNodes[1] !== undefined) {
                      count_comments = text2.nextElementSibling.childNodes[get_key_article_tools].childNodes[5].childNodes[1].nodeValue;
                  }

                  news_today.link = "http://www.dnevnik.bg" + link;
                  news_today.img_src = "http://www.dnevnik.bg" + img_src;
                  news_today.title = title;
                  news_today.description = description;

                  news_today.date = date;
                  news_today.author = author;
                  count_comments = count_comments.replace(/\s+/g, '');
                  news_today.count_comments = count_comments;

              } catch (e) {}

              news_today_content[i] = news_today;

          }
          createTableNewsToday(news_today_content);
      }
  };
  xhr.send();  
 
</script>
<?php
include ROOT . '/html/footer.inc';
