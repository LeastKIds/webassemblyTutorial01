import init from './pkg/rust.js'

const runWasm = async () => {
    const mycalc = await init("./pkg/rust_bg.wasm");

    const ret = mycalc.calculate_add(24, 30);

    document.body.textContent = `calculation result: ${ret}`;
}

runWasm();