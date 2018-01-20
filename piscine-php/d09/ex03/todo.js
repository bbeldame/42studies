function retrieveFromCSV() {
  var ft_todo = $("#ft_list");
  $.get("select.php", function (data) {
    data = JSON.parse(data);
    if (data && data.length > 0) {
      data.forEach(t => {
        var newDiv = `<div onclick="deleteTodo(this)">${t.replace("]p]p", ";")}</div>`;
        ft_todo.html(ft_todo.html() + newDiv);
      });
    }
  });
}

function deleteTodo(node) {
  var areYouSure = confirm("Are you sure about deleting this todo ?");
  var tmpNode = node;
  var idx = -1;
  while ((tmpNode = tmpNode.previousSibling) != null ) {
    idx++;
  }
  if (areYouSure === true) {
    node.remove();
    $.get("delete.php?id=" + idx);
  }
}

function newTodo() {
  var ft_todo = $("#ft_list");
  var txt = prompt("Name your todo :");
  if (txt) {
    var newDiv = `<div onclick="deleteTodo(this)">${txt}</div>`;
    ft_todo.html(newDiv + ft_todo.html());
    $.get("insert.php?value=" + txt);
  }
}

retrieveFromCSV();