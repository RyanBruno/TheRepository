// webpack.config.js
const { VueLoaderPlugin } = require("vue-loader")
const path = require("path")
const ESLintPlugin = require("eslint-webpack-plugin")
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
    mode: "development",
    module: {
        rules: [
            {
                test: /\.cson$/,
                loader: "cson-loader",
            },
            {
                test: /\.md$/,
                use: [
                    {
                        loader: "html-loader",
                    },
                    {
                        loader: "markdown-loader",
                    },
                ]
            },
            {
              test: /\.css$/,
              use: [
                "vue-style-loader",
                "css-loader",
              ]
            },
            {
                test: /\.vue$/,
                loader: "vue-loader",
            },
        ]
    },
    plugins: [
        new VueLoaderPlugin(),
        new ESLintPlugin(),
        new HtmlWebpackPlugin({
            filename: "rbruno.com.[fullhash].html",
            template: "./src/rbruno.com.html",
        }),
    ],
    entry: {
        rbruno_com: "./src/rbruno.com.js",
    },
    output: {
        filename: "rbruno.com.[fullhash].js",
        path: path.resolve(__dirname, "dist"),
        publicPath: "",
    },
}

