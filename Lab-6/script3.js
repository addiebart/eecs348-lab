addEventListener("DOMContentLoaded", () => {
    document.getElementById("btn").addEventListener("click", () => {
        let flag = false;
        let pass1 = document.getElementById("pass1").value;
        let pass2 = document.getElementById("pass2").value;
        if (pass1 == pass2) {
            flag = true;
        }
        if (pass1.length < 8) {
            alert("Password must be at least 8 characters");
        }
        else if (flag) {
            alert("Passwords Match");
        }
        else {
            alert("Passwords do not Match");
        }
    });
});