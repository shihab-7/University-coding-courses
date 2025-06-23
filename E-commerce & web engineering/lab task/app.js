document.addEventListener("DOMContentLoaded", () => {
    const Togglebtn = document.createElement("button");
    Togglebtn.textContent= "Dark Mode";

    Togglebtn.style.cssText =
    `
    position : fixed;
    top : 20px;
    right : 20px;
    padding : 10px 20px;
    background-color : #2c3e50;
    color : white;
    border : none;
    border-radius : 50%;
    cursor : pointer;
    z-index : 999;
    
    `;

    document.body.appendChild(Togglebtn);
    Togglebtn.addEventListener("click",()=>{
        document.body.classList.toggle("dark-mode");
    });
});