function toggle(a) {
    if (document.getElementById(a) != null) {
        if (document.getElementById(a).getAttribute("hid") == "1") {
            deplier(a)
        } else {
            plier(a)
        }
        console.log(document.getElementById(a).getAttribute("hid"))
    }
    else {
        console.log("-1");

    }
}

function plier(a) {
    if (document.getElementById(a) == null) {
    } else {
        document.getElementById(a).setAttribute("hid", "1")
    }
}

function deplier(a) {
    if (document.getElementById(a) == null) {
    } else {
        document.getElementById(a).setAttribute("hid", "0")
    }

}

function toutPlier() {
    var n = document.getElementById("acc").value

    for (let i = 1; i < n; i++) {
        plier(i)
    }
}

function toutDePlier() {
    var n = document.getElementById("acc").value

    for (let i = 1; i < n; i++) {
        deplier(i)
    }
}