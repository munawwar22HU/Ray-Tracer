let controller;
let slideScene;
let pageScene;
let detailScene;



const burger = document.querySelector('.burger');



function animateSlides(){
    controller = new ScrollMagic.Controller();

    const sliders = document.querySelectorAll('.slide');
    const nav = document.querySelector('.nav-header');

    sliders.forEach((slide, index, slides) => {
        const revealImg = slide.querySelector('.reveal-img');
        const img = slide.querySelector('img');
        const revealText = slide.querySelector('.reveal-text');

        //GSAP

        //pehla yeh hai k kya animate krna 
        //second time 
        //third pe object with properties jo jo change krni
        //gsap.to(revealImg, 1, {x:"100"})


        //gsap to mein yeh hota hai k sab ek saath chalna 
        //shuru hojata hai, toh isliye we'll make timeline
        const slideTl = gsap.timeline({defaults: {duration: 1, ease: 'power2.inOut'}})
        slideTl.fromTo(revealImg, {x: "0%"}, {x:'100%'});
        slideTl.fromTo(img, {scale:2}, {scale:1}, "-=0.25") //-=1 means k ek sec pehle run ho
        slideTl.fromTo(revealText, {x: "0%"}, {x:'100%'}, '-=0.75')
        slideTl.fromTo(nav, {y: '-100%'}, {y: '0%'}, '-=0.5')
        
        //Create a Scene
        slideScene =  new ScrollMagic.Scene({
            triggerElement: slide, 
            triggerHook : 0.25,
            reverse: false
        })
        .setTween(slideTl)
        .addTo(controller);

        
        //New Animation
        const pageTl = gsap.timeline();
        let nextSlide = slides.length -1 === index ? 'end' : slides[index+1];
        pageTl.fromTo(nextSlide,{y:'0%'}, {y:'50%'} );
        pageTl.fromTo(slide, {opacity:1, scale: 1}, {opacity:0, scale: 0.5});
        pageTl.fromTo(nextSlide,{y:'50%'}, {y:'0%'} , "-=0.3");
        //Create New Scene
        pageScene = new ScrollMagic.Scene({
            triggerElement: slide, 
            duration: '100%',
            triggerHook: 0
        })
        .setPin(slide, {pushFollowers: false})
        .setTween(pageTl)
        .addTo(controller)
            
    })
}

function navToggle(e) {
    if (!e.target.classList.contains("active")) {
      e.target.classList.add("active");
      gsap.to(".line1", 0.5, { rotate: "45", y: 5, background: "black" });
      gsap.to(".line2", 0.5, { rotate: "-45", y: -5, background: "black" });
      gsap.to("#logo", 1, { color: "black" });
      gsap.to(".nav-bar", 1, { clipPath: "circle(2500px at 100% -10%)" });
      document.body.classList.add("hide");
    } else {
      e.target.classList.remove("active");
      gsap.to(".line1", 0.5, { rotate: "0", y: 0, background: "white" });
      gsap.to(".line2", 0.5, { rotate: "0", y: 0, background: "white" });
      gsap.to("#logo", 1, { color: "white" });
      gsap.to(".nav-bar", 1, { clipPath: "circle(50px at 100% -10%)" });
      document.body.classList.remove("hide");
    }
  }





burger.addEventListener('click', navToggle);

animateSlides();