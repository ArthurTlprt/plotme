var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Plotme' });
});

router.get('/documentation', function(req, res, next) {
  res.render('documentation', { title: 'Plotme' });
});

module.exports = router;
