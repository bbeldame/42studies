function retrieveFromCookie() {
  var ft_todo = document.getElementById("ft_list");
  var cookie = document.cookie;
  var cookies = cookie.split(";");
  if (cookies.length > 0 && cookies[0]) {
    var todos = cookies.find(c => c.substring(0, 5) === "todos");
    var parsedTodos = todos.substring(6).split("][sep][");
    parsedTodos.forEach(t => {
      var newDiv = `<div onclick="deleteTodo(this)">${t.replace("]p]p", ";")}</div>`;
      ft_todo.innerHTML = ft_todo.innerHTML + newDiv;
    });
  }
}

function saveCookie() {
  var map = Array.prototype.map;
  var ft_todo = document.getElementById("ft_list");
  var parsedValue = [];
  ft_todo.childNodes.forEach(function (c) {
    if (c.innerHTML !== undefined) {
      parsedValue.push(c.innerHTML.replace(";", "]p]p"));
    }
  });
  var date = new Date();
  date.setTime(date.getTime() + (364 * 24 * 60 * 60 * 1000));
  document.cookie = `todos=${parsedValue.join("][sep][")}; expires=${date.toUTCString()};`;
}

function deleteTodo(node) {
  var areYouSure = confirm("Are you sure about deleting this todo ?");
  if (areYouSure === true) {
    node.remove();
    saveCookie();
  }
}

function newTodo() {
  var ft_todo = document.getElementById("ft_list");
  var txt = prompt("Name your todo :");
  if (txt) {
    var newDiv = `<div onclick="deleteTodo(this)">${txt}</div>`;
    ft_todo.innerHTML = newDiv + ft_todo.innerHTML;
    saveCookie();
  }
}

retrieveFromCookie();