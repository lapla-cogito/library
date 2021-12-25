$(function () {
            var TopBtn = $('#PageTopBtn');
            TopBtn.hide();
            $(window).scroll(function () {
                if ($(this).scrollTop() > 100) {
                    TopBtn.fadeIn();
                }
                else {
                    TopBtn.fadeOut();
                }
            });
            TopBtn.click(function () {
                $('body,html').animate({
                    scrollTop: 0
                }, 300);
                return false;
            });
        });