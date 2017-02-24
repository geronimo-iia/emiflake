(function() {
    'use strict';
    const Benchmark = require('benchmark');
    const UUID = require('uuid/v4');
    const suite = new Benchmark.Suite();
    const EmiFlake = require('..');

    const boundary = new EmiFlake(new Buffer("001422012345"), 48, 16, 64, 0);
    const twitter = new EmiFlake(new Buffer("mid"), 10, 12, 41, 365246060*1000);
    suite
        .add('Generate Twitter Snowflake', function () {
          boundary.generate();
        })
        .add('Generate Boundary Flake', function () {
          twitter.generate();
        })
        .add('UUID', function () {
          new UUID();
        })
        .on('cycle', function(event) {
            console.log(String(event.target));
        })
        .on('complete', function() {
            console.log('Fastest is ' + this.filter('fastest').map('name'));
        })
        .run({
            'async': true
        });
}());
