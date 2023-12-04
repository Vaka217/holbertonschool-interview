#!/usr/bin/node
const request = require('request')

const getCharacterName = (character) => {
  return new Promise((resolve, reject) => {
    request(character, (err, response, body) => {
      if (err) {
        console.log(err)
      } else {
        resolve(JSON.parse(body).name)
      }
    })
  })
}

request(
  `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`,
  async (err, response, body) => {
    if (err) {
      console.log(err)
    } else {
      const characters = JSON.parse(body).characters

      for (const character of characters) {
        const name = await getCharacterName(character)
        console.log(name)
      }
    }
  }
)
