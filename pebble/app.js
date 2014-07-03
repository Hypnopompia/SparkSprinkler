/* Create a new pebble.js project at cloudpebble.net and paste the code below into your app.js file */
var UI = require('ui');
var ajax = require('ajax');

var menu = new UI.Menu({
  sections: [{
             items: [{
                      title: 'Zone 1',
                      subtitle: 'Turn on Zone 1'
                     },{
                      title: 'Zone 2',
                      subtitle: 'Turn on Zone 2'
                     },{
                      title: 'Zone 3',
                      subtitle: 'Turn on Zone 3'
                     },{
                      title: 'Zone 4',
                      subtitle: 'Turn on Zone 4'
                     },{
                      title: 'Zone 5',
                      subtitle: 'Turn on Zone 5'
                     },{
                      title: 'Zone 6',
                      subtitle: 'Turn on Zone 6'
                     },{
                      title: 'Zone 7',
                      subtitle: 'Turn on Zone 7'
                     },{
                      title: 'Zone 8',
                      subtitle: 'Turn on Zone 8'
                     },{
                      title: 'Off',
                      subtitle: 'Turn all Zones off'
                     }]
             }]
});

menu.on('select', function(e) {
  var deviceID = "DEVICE_ID_HERE";
  var accessToken = "ACCESS_TOKEN_HERE";
  var zone = "";
  
  switch (e.item) {
    case 0: // Zone 1
      zone = "Zone1";
      break;
    case 1: // Zone 2
      zone = "Zone2";
      break;
    case 2: // Zone 3
      zone = "Zone3";
      break;
    case 3: // Zone 4
      zone = "Zone4";
      break;
    case 4: // Zone 5
      zone = "Zone5";
      break;
    case 5: // Zone 6
      zone = "Zone6";
      break;
    case 6: // Zone 7
      zone = "Zone7";
      break;
    case 7: // Zone 8
      zone = "Zone8";
      break;
    case 8: // Off
      zone = "Off";
      break;
  }

  console.log('Selected item: ' + e.section + ' ' + e.item);
  
  ajax(
    {
      url: "https://api.spark.io/v1/devices/" + deviceID + "/sprinkler",
      method: 'POST',
      type: 'json',
      headers: {
       'Authorization': "Bearer " + accessToken
      },
      data: {
        args: zone
      }
    },
    function(data) {
      console.log("Success");
    },
    function(error) {
      console.log('The ajax request failed: ' + JSON.stringify(error) );
    }
  );
  
});

menu.show();
