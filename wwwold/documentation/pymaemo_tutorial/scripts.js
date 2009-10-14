/* Original code from http://www.quirksmode.org */

function createTOC() {
  var y = document.createElement('div');
  y.id = 'innertoc';
  var a = y.appendChild(document.createElement('span'));
  a.onclick = showhideTOC;
  a.id = 'contentheader';
  a.innerHTML = 'show page contents';
  var z = y.appendChild(document.createElement('div'));
  z.onclick = showhideTOC;
  var toBeTOCced = getElementsByTagNames('h2,h3,h4,h5');
  if (toBeTOCced.length < 2) return false;

  /*
  for (var i=0;i<toBeTOCced.length;i++) {
    var tmp = document.createElement('a');
    tmp.innerHTML = toBeTOCced[i].innerHTML;
    tmp.className = 'page';
    z.appendChild(tmp);
    if (toBeTOCced[i].nodeName == 'H4')
      tmp.className += ' indent';
    if (toBeTOCced[i].nodeName == 'H5')
      tmp.className += ' extraindent';
    var headerId = toBeTOCced[i].id || 'link' + i;
    tmp.href = '#' + headerId;
    toBeTOCced[i].id = headerId;
    if (toBeTOCced[i].nodeName == 'H2') {
      tmp.innerHTML = 'Top';
      tmp.href = '#top';
      toBeTOCced[i].id = 'top';
    }
  }
  */

  var list = document.createElement('ul');
  y.appendChild(list);

  for (var i=0; i<toBeTOCced.length; i++) {
    var item = document.createElement('li');
    var lnk = document.createElement('a');
    lnk.innerHTML = toBeTOCced[i].innerHTML;
    item.appendChild(lnk);
    list.appendChild(item);

    if (toBeTOCced[i].nodeName == 'H3')
      item.className = 'toc_h3';
    if (toBeTOCced[i].nodeName == 'H4')
      item.className = 'toc_h4';

    var headerId = toBeTOCced[i].id || 'link' + i;
    lnk.href = '#' + headerId;
    toBeTOCced[i].id = headerId;
  }

  return y;
}

var TOCstate = 'none';

function showhideTOC() {
  TOCstate = (TOCstate == 'none') ? 'block' : 'none';
  var newText = (TOCstate == 'none') ? 'show page contents' : 'hide page contents';
  document.getElementById('contentheader').innerHTML = newText;
  document.getElementById('innertoc').lastChild.style.display = TOCstate;
}

/*************************/

function getElementsByTagNames(list,obj) {
  if (!obj) var obj = document;
  var tagNames = list.split(',');
  var resultArray = new Array();
  for (var i=0;i<tagNames.length;i++) {
    var tags = obj.getElementsByTagName(tagNames[i]);
    for (var j=0;j<tags.length;j++) {
      resultArray.push(tags[j]);
    }
  }
  var testNode = resultArray[0];
  if (!testNode) return [];
  if (testNode.sourceIndex) {
    resultArray.sort(function (a,b) {
        return a.sourceIndex - b.sourceIndex;
    });
  }
  else if (testNode.compareDocumentPosition) {
    resultArray.sort(function (a,b) {
        return 3 - (a.compareDocumentPosition(b) & 6);
    });
  }
  return resultArray;
}




window.onload = function () {
  var ToC = createTOC();
  if (ToC)
    document.getElementById('minitoc-area').appendChild(ToC);

  showhideTOC();
}