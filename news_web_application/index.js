console.log("This is my index.js file");

// inititalize the news api parameters. 
// let source = 'the-times-of-india';
let source = 'bbc-news';
let apiKey = 'a75c03ca3b0a4c62907a98eb6902211d';

// grab the news container. 
let newsAccordian = document.getElementById('newsAccordian');
// console.log(newsAccordian);

// get an ajax 'GET' request. 
const xhr = new XMLHttpRequest();
xhr.open('GET', `https://newsapi.org/v2/top-headlines?sources=${source}&apiKey=${apiKey}`, true);
https://newsapi.org/v2/top-headlines?sources=bbc-news&apiKey=a75c03ca3b0a4c62907a98eb6902211d

xhr.onload = function () {
    if (this.status === 200) {
        let json = JSON.parse(this.responseText);
        let articles = json.articles;
        // console.log(articles);
        let newsHTML = "";
        articles.forEach(function (element, index) {
            // console.log(articles[news]);
            let html = `
                    <div class="accordion" id="newsAccordian">
                        <div class="accordion-item">
                            <h2 class="accordion-header" id="heading${index}">
                                <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse"
                                    data-bs-target="#collapse${index}" aria-expanded="false" aria-controls="collapse${index}">
                                   <b>Breaking News ${index+1}:</b> ${element.title}
                                </button>
                            </h2>
                            <div id="collapse${index}" class="accordion-collapse collapse" aria-labelledby="heading${index}"
                                data-bs-parent="#accordionExample">
                                <div class="accordion-body">${element.content}. <a href = "${element.url}" target = "_blank">Read More</a></div>
                            </div>
                        </div>
                    </div> `
            newsHTML += html;
        });
        newsAccordian.innerHTML = newsHTML;
    }
    else {
        console.log("Some error occured");
    }
}

xhr.send();


