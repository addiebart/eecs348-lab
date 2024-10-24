addEventListener("DOMContentLoaded", () => {
    document.querySelector("#btn").addEventListener("click", () => {
        let textr = document.querySelector("#textr").value;
        let textg = document.querySelector("#textg").value;
        let textb = document.querySelector("#textb").value;
        let borderr = document.querySelector("#borderr").value;
        let borderg = document.querySelector("#borderg").value;
        let borderb = document.querySelector("#borderb").value;
        let borderwidth = document.querySelector("#borderwidth").value;
        document.querySelector("#inner").style.color = `rgb(${textr}, ${textg}, ${textb})`;
        document.querySelector("#outer").style.border = `${borderwidth}px solid rgb(${borderr}, ${borderg}, ${borderb})`;
    });
});