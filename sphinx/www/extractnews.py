try:
    import simplejson as json
except ImportError:
    import json

import codecs

NUM_NEWS = 2

f = codecs.open("_build/json/news.fjson", "r", "utf-8")
if not f:
    raise "Run make json before make html!"

strdata = "".join(f.readlines())
f.close()

news = json.loads(strdata)
lines = news[u"body"].split("\n")
lines = lines[2:len(lines)-2]

contents = []
news_count = 0;
LINE_MATCHER = "<div class=\"section\" id="
for line in lines:
    if line[:len(LINE_MATCHER)] == LINE_MATCHER:
        news_count += 1
        if news_count > NUM_NEWS:
            break
    contents.append(line)

f = codecs.open("_templates/latests_news.html", "w", "utf-8")
f.write("\n".join(contents))
f.close()

